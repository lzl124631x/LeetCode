var data = await (await fetch('https://leetcode.com/api/problems/algorithms/')).json();
var q = data.stat_status_pairs;
var unlocked = q.filter(x => !x.paid_only)
var locked = q.filter(x => x.paid_only)
var f = (s) => unlocked.filter(x => x.status === s);
var ac = f("ac")
var at = f("notac")
var todo = f(null)
var d = (qs, s) => qs.filter(x => x.difficulty.level === s);
var breakdown = (qs) => `(${[1,2,3].map(s => d(qs, s).length).join('/')})`;
var stat = (qs) => `${qs.length} ${breakdown(qs)}`
var kv = [
    [ "Total", stat(q) ],
    [ "Locked", stat(locked) ],
    [ "Unlked", stat(unlocked) ],
    [ "Solved", stat(ac) ],
    [ "Attmpt", stat(at)],
    [ "Todo", stat(todo)],
]
console.log(kv.map(x => x.join(":\t")).join("\n"))