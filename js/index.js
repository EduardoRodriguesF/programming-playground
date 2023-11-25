const path = require('node:path');
const { Worker } = require('node:worker_threads');


function fn2workerURL(fn) {
  const blob = new Blob([`(${fn.toString()})()`], { type: "text/javascript" });
  return URL.createObjectURL(blob);
}

const worker = new Worker(fn2workerURL((e) => {
    console.log(e)
    console.log('I work')
}))
