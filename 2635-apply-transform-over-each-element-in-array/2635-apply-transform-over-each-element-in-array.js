/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let nArr = [];
    for(let i=0;i<arr.length;i++){
        nArr.push(fn(arr[i], i));
    }
    return nArr;
};