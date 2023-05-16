/**
 * @param {number} millis
 */
async function sleep(millis) {
    return new Promise(function(resolve, reject){
        if(millis === undefined || isNaN(millis)){
            reject();
        }else{
            setTimeout(resolve, millis);
        }
    });
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */