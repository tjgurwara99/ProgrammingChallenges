var n = parseInt(readline());
var xs = readline().split(" ").map(function(x) { return parseInt(x); });

xs.sort(function (a,b) { return a-b; });

function gcd(a, b) {
    var c = 0;
    while (b !== 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

var totalGCD = xs[1] - xs[0];

for (var i = 1; i < n; i++) {
    totalGCD = gcd(totalGCD, xs[i] - xs[i-1]);
}

var ans = 0;
for (i = 1; i < n; i++) {
    ans += Math.floor((xs[i] - xs[i-1] - 1) / totalGCD);
}

print(ans);