
let is_lock = false 
let count = 0

/*setTimeout(() => {*/

  //setTimeout(() => {
    //console.log('done: ', Date.now())
  //}, 1000)
  
  //setTimeout(() => {
    //console.log('done2: ', Date.now())
  //}, 2000)

  //console.log('begin: ', Date.now())
  //while (!is_lock)  {
    //if (count === 100000000) {
      //is_lock = true
    //}
    //++count
    //// console.log(++count)
  //}
  
//}, 1000)



var clock = setInterval(() => {
  if (count === 0) {
    console.log('begin: ', Date.now())
    while(!is_lock) {
      if (count === 1000000000 ) {
        is_lock = true
      }
    ++count
    }
  } else {
    console.log('cur', Date.now())
  }

}, 1000)


// https://juejin.im/post/5a6547d0f265da3e283a1df7
