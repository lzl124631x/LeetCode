!function(d) {
    var $ = (selector, startNode) => (startNode || document).querySelector(selector);
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
    title = $('[data-cy=question-title]').textContent.trim();
    copy(`${title.replace('.', ' |')} | ${$('[diff]').textContent} | [Solution](leetcode/${encodeURIComponent(title.trim())})`)
}(document)
