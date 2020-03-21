!function(d) {
    var $=d.querySelector.bind(d);
    var $$=d.querySelectorAll.bind(d);
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
    var link = location.href.replace(/submissions\/$/, '')
    copy(`// OJ: ${link}\n// Author: github.com/lzl124631x\n// Time: O()\n// Space: O()\n${Array.from($$('span[role="presentation"]')).map(x => x.textContent.replace(/[^\x00-\x7F]/g, ' ')).filter(x => !/^\s*$/g.test(x)).join('\n')}`)
}(document)
