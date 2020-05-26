var title = $('.problem-statement .header .title').text().replace(/^.*?\.\s/, '');
var content = $('.problem-statement').html().trim();
copy(`# [${title}](${location.href})\n\n${content}\n\n## Solution 1.\n\n\`\`\`cpp\n// OJ: ${location.href}\n// Author: github.com/lzl124631x\n// Time: O()\n// Space: O()\n\n\`\`\``);