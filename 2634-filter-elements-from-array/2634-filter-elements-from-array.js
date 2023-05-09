/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let nArr = [];
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i], i)){
            nArr.push(arr[i]);
        }
    }
    return nArr;
};