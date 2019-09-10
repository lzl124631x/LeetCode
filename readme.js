title = $('[data-cy=question-title]').textContent.trim();
copy(`${title.replace('.', ' |')} | ${$('[diff]').textContent} | [Solution](leetcode/${encodeURIComponent(title.trim())})`)