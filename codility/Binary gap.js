function solution(N) {
    // 십진수 N을 2진수 String으로 변환
    const binStr = N.toString(2);
    
    // 처음에 위치한 1과 마지막에 위치한 1을 기준으로 문자열을 slice, ex) 00110001001011000 => 1000100101
    const binGaps = binStr.slice(binStr.indexOf('1') + 1, binStr.lastIndexOf('1'));
    
    // slice된 binGaps 문자열 내부의 1을 기준으로 0의 길이를 split, ex) 1000100101 (000, 00, 0)
    const zeroCounted = binGaps.split('1').map(zeros => zeros.length);

    // zeroCounted의 max length return
    return zeroCounted.length ? Math.max(...zeroCounted) : 0;
}