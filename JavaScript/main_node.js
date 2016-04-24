var x = require('./atdc_sort');

var arr = [];
for (var i = 0; i < 2; i++) {
    arr[i] = Math.floor(Math.random() * 201) - 100;
}
console.log(arr);

x.atdc_sort(arr, 0, arr.length);

console.log(arr);