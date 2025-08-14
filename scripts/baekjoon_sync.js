// BaekjoonHub 자동 동기화 스크립트
// 사용법: 백준 "맞은 문제" 페이지에서 개발자 도구 콘솔에 붙여넣기

async function syncAllProblems() {
    console.log('🚀 BaekjoonHub 자동 동기화 시작...');
    
    // 모든 문제 링크 가져오기
    const problemLinks = Array.from(document.querySelectorAll('.problem_number a'));
    
    if (problemLinks.length === 0) {
        console.error('❌ 문제를 찾을 수 없습니다. "맞은 문제" 페이지에서 실행해주세요.');
        return;
    }
    
    console.log(`📊 총 ${problemLinks.length}개 문제 발견`);
    
    // 각 문제 순차적으로 처리
    for (let i = 0; i < problemLinks.length; i++) {
        const link = problemLinks[i];
        const problemId = link.textContent;
        const problemUrl = link.href;
        
        console.log(`\n[${i + 1}/${problemLinks.length}] 문제 ${problemId} 처리 중...`);
        
        try {
            // 문제 페이지 열기
            const problemWindow = window.open(problemUrl, '_blank');
            
            // 페이지 로드 대기
            await new Promise(resolve => setTimeout(resolve, 3000));
            
            // 제출 탭으로 이동
            problemWindow.location.href = `https://www.acmicpc.net/status?from_mine=1&problem_id=${problemId}&user_id=${document.querySelector('.username').textContent}`;
            
            // 제출 목록 로드 대기
            await new Promise(resolve => setTimeout(resolve, 2000));
            
            // 첫 번째 AC 제출 클릭 (BaekjoonHub가 자동으로 감지)
            problemWindow.document.querySelector('tr[id^="solution-"] td:first-child a')?.click();
            
            // BaekjoonHub 처리 대기
            await new Promise(resolve => setTimeout(resolve, 2000));
            
            // 창 닫기
            problemWindow.close();
            
            console.log(`✅ 문제 ${problemId} 완료`);
            
        } catch (error) {
            console.error(`❌ 문제 ${problemId} 처리 실패:`, error);
        }
        
        // GitHub API 제한 방지를 위한 대기
        if ((i + 1) % 10 === 0) {
            console.log('⏸️ GitHub API 제한 방지를 위해 10초 대기...');
            await new Promise(resolve => setTimeout(resolve, 10000));
        }
    }
    
    console.log('\n✨ 모든 문제 동기화 완료!');
}

// 더 간단한 버전 - 제출 페이지만 순차 방문
async function syncSimple() {
    console.log('🚀 간단한 동기화 시작...');
    
    // 문제 번호만 포함된 링크 필터링 (숫자로만 된 문제 링크)
    let problemLinks = Array.from(document.querySelectorAll('a[href*="/problem/"]'))
        .filter(link => {
            const match = link.href.match(/\/problem\/(\d+)$/);
            return match && match[1]; // 숫자로 끝나는 링크만
        });
    
    // 중복 제거
    const uniqueProblems = new Map();
    problemLinks.forEach(link => {
        const problemId = link.href.match(/\/problem\/(\d+)$/)[1];
        if (!uniqueProblems.has(problemId)) {
            uniqueProblems.set(problemId, link);
        }
    });
    problemLinks = Array.from(uniqueProblems.values());
    
    const username = document.querySelector('.username')?.textContent || 
                     document.querySelector('a.username')?.textContent;
    
    if (!username) {
        console.error('❌ 로그인이 필요합니다.');
        return;
    }
    
    console.log(`📊 총 ${problemLinks.length}개 문제를 ${username} 계정으로 동기화`);
    
    for (let i = 0; i < problemLinks.length; i++) {
        // 문제 번호 추출 (href에서 추출 또는 텍스트에서 추출)
        let problemId;
        if (problemLinks[i].href) {
            problemId = problemLinks[i].href.match(/\/problem\/(\d+)/)?.[1] || problemLinks[i].textContent;
        } else {
            problemId = problemLinks[i].textContent;
        }
        
        console.log(`[${i + 1}/${problemLinks.length}] 문제 ${problemId} 처리 중...`);
        
        // 새 탭에서 제출 페이지 열기
        const url = `https://www.acmicpc.net/status?from_mine=1&problem_id=${problemId}&user_id=${username}`;
        window.open(url, '_blank');
        
        // 다음 문제로 넘어가기 전 대기
        await new Promise(resolve => setTimeout(resolve, 3000));
        
        // 10개마다 긴 대기
        if ((i + 1) % 10 === 0) {
            console.log('⏸️ 10초 대기 중...');
            await new Promise(resolve => setTimeout(resolve, 10000));
        }
    }
    
    console.log('✨ 모든 탭 열기 완료! 각 탭에서 첫 번째 제출을 클릭하면 BaekjoonHub가 자동 동기화합니다.');
}

// 페이지 구조 확인 함수
function checkPage() {
    console.log('🔍 페이지 구조 확인 중...');
    
    // 실제 문제 링크만 필터링
    const allLinks = Array.from(document.querySelectorAll('a[href*="/problem/"]'));
    const problemLinks = allLinks.filter(link => {
        const match = link.href.match(/\/problem\/(\d+)$/);
        return match && match[1];
    });
    
    // 중복 제거
    const uniqueProblems = new Set();
    problemLinks.forEach(link => {
        const problemId = link.href.match(/\/problem\/(\d+)$/)[1];
        uniqueProblems.add(problemId);
    });
    
    console.log(`📊 전체 링크: ${allLinks.length}개`);
    console.log(`✅ 실제 문제 링크: ${problemLinks.length}개`);
    console.log(`🎯 중복 제거 후: ${uniqueProblems.size}개 문제`);
    
    if (problemLinks.length > 0) {
        console.log('샘플 문제 번호:', Array.from(uniqueProblems).slice(0, 5).join(', '), '...');
    }
    
    // 현재 페이지 URL 확인
    console.log('📍 현재 페이지:', window.location.href);
    
    const username = document.querySelector('.username')?.textContent || 
                     document.querySelector('a.username')?.textContent;
    console.log('👤 사용자:', username);
    
    return uniqueProblems.size;
}

// 일부만 동기화 (테스트용)
async function syncPartial(count = 10) {
    console.log(`🚀 처음 ${count}개 문제만 동기화 시작...`);
    
    // 문제 번호만 포함된 링크 필터링
    let problemLinks = Array.from(document.querySelectorAll('a[href*="/problem/"]'))
        .filter(link => {
            const match = link.href.match(/\/problem\/(\d+)$/);
            return match && match[1];
        });
    
    // 중복 제거
    const uniqueProblems = new Map();
    problemLinks.forEach(link => {
        const problemId = link.href.match(/\/problem\/(\d+)$/)[1];
        if (!uniqueProblems.has(problemId)) {
            uniqueProblems.set(problemId, link);
        }
    });
    problemLinks = Array.from(uniqueProblems.values()).slice(0, count); // 지정한 개수만
    
    const username = document.querySelector('.username')?.textContent || 
                     document.querySelector('a.username')?.textContent;
    
    console.log(`📊 ${problemLinks.length}개 문제 동기화 시작 (${username})`);
    console.log('⚠️ 팝업 차단이 있다면 해제해주세요!');
    
    // 첫 번째 탭은 바로 열기 (팝업 차단 테스트)
    const firstUrl = `https://www.acmicpc.net/status?from_mine=1&problem_id=${problemLinks[0].href.match(/\/problem\/(\d+)$/)[1]}&user_id=${username}`;
    const firstTab = window.open(firstUrl, '_blank');
    
    if (!firstTab) {
        console.error('❌ 팝업이 차단되었습니다! 브라우저 주소창에서 팝업 차단을 해제하고 다시 실행하세요.');
        return;
    }
    
    console.log('[1/' + problemLinks.length + '] 문제 ' + problemLinks[0].href.match(/\/problem\/(\d+)$/)[1] + ' 탭 열림');
    
    // 나머지 탭들 열기
    for (let i = 1; i < problemLinks.length; i++) {
        await new Promise(resolve => setTimeout(resolve, 2000));
        
        let problemId = problemLinks[i].href.match(/\/problem\/(\d+)$/)[1];
        console.log(`[${i + 1}/${problemLinks.length}] 문제 ${problemId} 처리 중...`);
        
        const url = `https://www.acmicpc.net/status?from_mine=1&problem_id=${problemId}&user_id=${username}`;
        const newTab = window.open(url, '_blank');
        
        if (!newTab) {
            console.warn(`⚠️ 문제 ${problemId} 탭 열기 실패 (팝업 차단?)`);
        }
    }
    
    console.log('✨ 완료! 열린 탭에서 첫 번째 제출을 클릭하세요.');
}

// 범위 지정 동기화
async function syncRange(start, count = 20) {
    console.log(`🚀 ${start}번째부터 ${count}개 문제 동기화 시작...`);
    
    // 문제 번호만 포함된 링크 필터링
    let problemLinks = Array.from(document.querySelectorAll('a[href*="/problem/"]'))
        .filter(link => {
            const match = link.href.match(/\/problem\/(\d+)$/);
            return match && match[1];
        });
    
    // 중복 제거
    const uniqueProblems = new Map();
    problemLinks.forEach(link => {
        const problemId = link.href.match(/\/problem\/(\d+)$/)[1];
        if (!uniqueProblems.has(problemId)) {
            uniqueProblems.set(problemId, link);
        }
    });
    
    // 지정된 범위만 선택
    problemLinks = Array.from(uniqueProblems.values()).slice(start - 1, start - 1 + count);
    
    if (problemLinks.length === 0) {
        console.log('❌ 해당 범위에 문제가 없습니다.');
        return;
    }
    
    const username = document.querySelector('.username')?.textContent || 
                     document.querySelector('a.username')?.textContent;
    
    console.log(`📊 ${problemLinks.length}개 문제 동기화 (${username})`);
    
    for (let i = 0; i < problemLinks.length; i++) {
        let problemId = problemLinks[i].href.match(/\/problem\/(\d+)$/)[1];
        console.log(`[${i + 1}/${problemLinks.length}] 문제 ${problemId} 처리 중...`);
        
        const url = `https://www.acmicpc.net/status?from_mine=1&problem_id=${problemId}&user_id=${username}`;
        window.open(url, '_blank');
        
        await new Promise(resolve => setTimeout(resolve, 2000));
    }
    
    console.log(`✨ ${start}~${start + problemLinks.length - 1}번째 완료!`);
    console.log(`다음 실행: syncRange(${start + count}, 20)`);
}

// 전체 자동 분할 실행
async function syncAll20() {
    const total = checkPage();
    const rounds = Math.ceil(total / 20);
    
    console.log(`📊 총 ${total}개 문제를 20개씩 ${rounds}번에 나눠 처리합니다.`);
    console.log('각 라운드는 수동으로 실행해주세요:\n');
    
    for (let i = 0; i < rounds; i++) {
        console.log(`syncRange(${i * 20 + 1}, 20)  // ${i + 1}번째 그룹`);
    }
}

// 특정 문제 번호들만 동기화
async function syncSpecific(problemIds) {
    if (!Array.isArray(problemIds)) {
        console.error('❌ 배열 형태로 문제 번호를 입력해주세요. 예: [1000, 1001, 1002]');
        return;
    }
    
    console.log(`🎯 지정된 ${problemIds.length}개 문제 동기화 시작...`);
    
    const username = document.querySelector('.username')?.textContent || 
                     document.querySelector('a.username')?.textContent;
    
    if (!username) {
        console.error('❌ 로그인이 필요합니다.');
        return;
    }
    
    console.log(`📊 문제 번호들: ${problemIds.slice(0, 10).join(', ')}${problemIds.length > 10 ? '...' : ''}`);
    
    for (let i = 0; i < problemIds.length; i++) {
        const problemId = problemIds[i];
        console.log(`[${i + 1}/${problemIds.length}] 문제 ${problemId} 처리 중...`);
        
        const url = `https://www.acmicpc.net/status?from_mine=1&problem_id=${problemId}&user_id=${username}`;
        window.open(url, '_blank');
        
        await new Promise(resolve => setTimeout(resolve, 2000));
        
        // 10개마다 긴 대기
        if ((i + 1) % 10 === 0) {
            console.log('⏸️ 10초 대기 중...');
            await new Promise(resolve => setTimeout(resolve, 10000));
        }
    }
    
    console.log('✨ 완료! 열린 탭에서 첫 번째 제출을 클릭하세요.');
}

// 빠진 문제 찾기 (GitHub vs 실제 푼 문제)
function findMissingAndSync() {
    // 사용자가 백준에서 실제로 푼 전체 문제 목록
    const solvedProblems = [
        1000, 1001, 1002, 1003, 1005, 1008, 1011, 1012, 1018, 1026, 1027, 1043, 1065, 1074, 1085, 1106, 1107, 1110, 1149, 1152, 1157, 1158, 1162, 1167, 1181, 1182, 1193, 1197, 1202, 1208, 1238, 1259, 1260, 1261, 1275, 1300, 1305, 1309, 1316, 1330, 1389, 1427, 1431, 1436, 1450, 1463, 1476, 1495, 1504, 1509, 1515, 1517, 1520, 1541, 1546, 1562, 1613, 1620, 1629, 1644, 1647, 1654, 1655, 1676, 1697, 1699, 1707, 1708, 1712, 1715, 1717, 1725, 1748, 1753, 1759, 1764, 1766, 1780, 1786, 1789, 1790, 1799, 1806, 1854, 1865, 1874, 1912, 1916, 1918, 1920, 1922, 1924, 1927, 1929, 1931, 1932, 1948, 1966, 1967, 1976, 1978, 1987, 1991, 1992, 2003, 2042, 2056, 2096, 2098, 2108, 2133, 2150, 2156, 2162, 2164, 2166, 2178, 2206, 2210, 2217, 2225, 2231, 2239, 2243, 2252, 2261, 2263, 2292, 2293, 2309, 2357, 2438, 2439, 2442, 2447, 2448, 2467, 2468, 2470, 2473, 2475, 2477, 2493, 2504, 2512, 2523, 2527, 2557, 2559, 2562, 2573, 2577, 2579, 2580, 2581, 2588, 2606, 2609, 2618, 2623, 2630, 2638, 2667, 2675, 2739, 2741, 2742, 2750, 2751, 2753, 2775, 2798, 2805, 2839, 2869, 2884, 2908, 2920, 2941, 2957, 3009, 3052, 3053, 3055, 3085, 3190, 3273, 4153, 4344, 4354, 4673, 4948, 4949, 5052, 5430, 5525, 5622, 5639, 5670, 6064, 6549, 6588, 6603, 7453, 7562, 7568, 7569, 7576, 7578, 7662, 8393, 8958, 9012, 9019, 9020, 9095, 9250, 9251, 9252, 9328, 9375, 9461, 9465, 9466, 9498, 9663, 9935, 10026, 10171, 10172, 10250, 10430, 10718, 10773, 10775, 10799, 10809, 10814, 10815, 10816, 10817, 10818, 10819, 10828, 10830, 10844, 10845, 10866, 10868, 10869, 10870, 10871, 10872, 10942, 10950, 10951, 10952, 10971, 10972, 10973, 10974, 10989, 10996, 10998, 10999, 11000, 11003, 11021, 11022, 11047, 11048, 11049, 11050, 11052, 11053, 11054, 11279, 11286, 11399, 11403, 11404, 11444, 11505, 11585, 11650, 11651, 11654, 11657, 11659, 11660, 11720, 11723, 11724, 11725, 11726, 11727, 11729, 11758, 11779, 11780, 11866, 12015, 12100, 12738, 12844, 12851, 12852, 12865, 13172, 13459, 13460, 13549, 13913, 14002, 14003, 14225, 14226, 14391, 14425, 14500, 14501, 14502, 14503, 14626, 14681, 14888, 14889, 14938, 14940, 15552, 15596, 15649, 15650, 15651, 15652, 15654, 15655, 15656, 15657, 15663, 15664, 15665, 15666, 15681, 15686, 15818, 15829, 15989, 16194, 16236, 16928, 16935, 16953, 17070, 17089, 17144, 17219, 17298, 17386, 17387, 17404, 17626, 18110, 18111, 18258, 18290, 18870, 20040, 21736, 25083, 27172, 27866, 28702, 28707, 30802, 30804, 30805, 31403
    ];
    
    // 현재 백준 "맞은 문제" 페이지에서 GitHub에 올라온 문제들 추출
    const uploadedProblems = Array.from(document.querySelectorAll('a[href*="/problem/"]'))
        .filter(link => {
            const match = link.href.match(/\/problem\/(\d+)$/);
            return match && match[1];
        })
        .map(link => parseInt(link.href.match(/\/problem\/(\d+)$/)[1]))
        .filter(id => !isNaN(id));
    
    const uploadedSet = new Set(uploadedProblems);
    
    // 실제로 푼 문제 중에서 GitHub에 올라가지 않은 문제들 찾기
    const missingProblems = solvedProblems.filter(id => !uploadedSet.has(id));
    
    console.log(`📊 분석 결과:`);
    console.log(`✅ 백준에서 푼 전체 문제: ${solvedProblems.length}개`);
    console.log(`✅ 현재 GitHub에 올라온 문제: ${uploadedProblems.length}개`);
    console.log(`❌ GitHub에 빠진 문제: ${missingProblems.length}개`);
    
    if (missingProblems.length > 0) {
        console.log(`🔍 GitHub에 빠진 문제 번호들:`);
        // 20개씩 줄바꿈해서 보기 쉽게
        const chunks = [];
        for (let i = 0; i < missingProblems.length; i += 20) {
            chunks.push(missingProblems.slice(i, i + 20).join(', '));
        }
        chunks.forEach(chunk => console.log(chunk));
        
        console.log(`\n🚀 빠진 문제들을 동기화하려면:`);
        console.log(`syncMissing()  // ${missingProblems.length}개 문제 동기화`);
        
        // 빠진 문제 목록을 전역 변수에 저장
        window.missingProblems = missingProblems;
        
        return missingProblems;
    } else {
        console.log('🎉 모든 문제가 GitHub에 정상적으로 올라가 있습니다!');
        return [];
    }
}

// 빠진 문제들만 동기화
async function syncMissing() {
    if (!window.missingProblems || window.missingProblems.length === 0) {
        console.log('먼저 findMissingAndSync()를 실행하여 빠진 문제를 찾아주세요.');
        return;
    }
    
    await syncSpecific(window.missingProblems);
}

// 실행 안내
console.log(`
==============================================
🎯 BaekjoonHub 자동 동기화 스크립트
==============================================

사용 가능한 명령어:
1. checkPage() - 현재 페이지 구조 확인
2. findMissingAndSync() - 빠진 문제 찾기 (신규!)
3. syncMissing() - 빠진 문제들만 동기화 (신규!)
4. syncSpecific([1000, 1001, 1002]) - 특정 문제들만 동기화 (신규!)
5. syncRange(1, 20) - 범위별 동기화
6. syncAll20() - 전체 명령어 목록

빠진 문제 찾기 & 동기화:
> findMissingAndSync()  // 빠진 문제 확인
> syncMissing()         // 빠진 문제들만 동기화

특정 문제만 동기화:
> syncSpecific([1234, 5678, 9012])
==============================================
`);