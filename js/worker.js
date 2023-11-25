let sum = 0

for (let i = 0; i < 999999999; i++) {
    sum += i;
}

this.postMessage(sum)
