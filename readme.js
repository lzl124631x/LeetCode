let title = $('.css-1ponsav').textContent.trim();
copy(`${title.replace('.', ' |')} | ${$('[diff]').textContent} | [Solution](leetcode/${encodeURIComponent(title.trim())})`)