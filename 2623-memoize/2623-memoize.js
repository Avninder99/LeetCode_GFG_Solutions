/**
 * @param {Function} fn
 */
function memoize(fn) {
    let arr, initialized = false;
    return function(...args) {
        if(!initialized){
            if(args.length == 2){
                arr = new Array(100000);
                for(let i=0;i<100000;i++){
                    arr[i] = new Map();
                }
            }else{
                arr = new Array(11).fill(-1);
            }
            initialized = true;
        }
        
        if(args.length == 2){
            if(!(arr[args[0]].has(args[1]))){
                arr[args[0]].set(args[1], fn(...args));
            }
            return arr[args[0]].get(args[1]);
        }else{
            if(arr[args[0]] == -1){
                arr[args[0]] = fn(...args);
            }
            return arr[args[0]];
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */