/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = (fn, t) => {
  let interval = null;
  let queuedArgs = null;

  const processArgs = () => {
    if (queuedArgs === null) {
      clearInterval(interval);
      interval = null;
    } else {
      fn(...queuedArgs);
      queuedArgs = null;
    }
  };

  return (...args) => {
    if (interval) {
      queuedArgs = args;
    } else {
      fn(...args);
      interval = setInterval(processArgs, t);
    }
  };
};
/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */