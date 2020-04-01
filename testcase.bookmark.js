!function(d) {
    var $ = (selector, startNode) => (startNode || document).querySelector(selector);
    var $$=d.querySelectorAll.bind(d);
    var s=$('.source-content'); // In context, there is a source-content with the same testcases, ignore it.
    s&&s.parentNode.removeChild(s);
    function copy(str) { // Chrome Console API is not available :( Have to use this way.
        const el = d.createElement('textarea');
        el.value = str;
        el.setAttribute('readonly', '');
        el.style.position = 'absolute';
        el.style.left = '-9999px';
        d.body.appendChild(el);
        el.select();
        d.execCommand('copy');
        d.body.removeChild(el);
    }
    function flattenArray(s) { // remove \n and useless spaces within array
        var c = 0, o = '', a = '';
        for (var i = 0; i < s.length; ++i) {
            if (s[i] === '[') ++c;
            else if (s[i] === ']') --c;
            if (c || s[i] === ']') { // within array
                a += s[i];
                if (s[i] === ']') {
                    o += a.split('\n').map(x => x.trim()).join('');
                    a = '';
                }
            } else o += s[i];
        }
        return o;
    }
    var t = Array.from($$('strong, b')).filter(x=>x.innerText.trim().match(/Input:?/)).map(x=>{
        var x = x.nextSibling;
        var t = '';
        while (x && x.nextSibling) {
            t += x.textContent;
            x = x.nextSibling;
            if (x && (x.tagName === "STRONG" || x.tagName === "B") && x.innerText.match(/Output:?.*/)) break;
        }
        t = flattenArray(t);
        if (t.includes('=')) t = t.split(/\,?\s*\w+\s*=\s*/g).filter(x => x).map(x => x.split('\n').map(x => x.trim()).join('')).join('\n')
        return t.trim()
    }).join('\n');
    copy(t);
    console.log(t)
    var a=$('#textArea');
    if (a) {
        $('#custom_testcase').checked = true;
        $('.testcase-input-base').className = 'testcase-input-base';
        a.focus();
        a.select();
        // Directly setting the value of textarea doesn't work because the viewModel of LeetCode resets it when you click "Run"
        // document.execCommand('paste') doesn't work because it's blocked by Chrome by default
    }
}(document)