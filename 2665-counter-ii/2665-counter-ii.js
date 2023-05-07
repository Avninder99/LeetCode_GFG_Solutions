/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */

class myCounter {
    constructor(init){
        this.x = init;
        this.r = init;
    }
    increment() {
        this.x = this.x + 1;
        return this.x;
    }
    decrement() {
        this.x = this.x - 1;
        return this.x;
    }
    reset() {
        this.x = this.r;
        return this.x;
    }
    
}
var createCounter = function(init) {
    return new myCounter(init);
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */