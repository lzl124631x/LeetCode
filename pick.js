var data = await (await fetch('https://leetcode.com/api/problems/algorithms/')).json();
var q = data.stat_status_pairs.filter(x => !x.paid_only && x.status !== "ac")
var r = () => q[Math.floor(Math.random() * q.length)]
var d = (x) => ['Easy', 'Medium', 'Hard'][x - 1]
var f = (x) => `${x.stat.frontend_question_id}. ${x.stat.question__title} (${d(x.difficulty.level)})\nhttps://leetcode.com/problems/${x.stat.question__title_slug}`
f(r())