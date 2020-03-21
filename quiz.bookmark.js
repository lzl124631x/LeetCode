!function(d) {
    var $=d.querySelector.bind(d);
    var $$=(sl) => Array.from(d.querySelectorAll(sl));
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
    var title = `# [${$('[data-cy=question-title]').textContent} (${$('[diff]').textContent})](${location.href})\n\n`;
    var question = `${$('.question-content__JfgR').children[0].innerHTML}\n\n`;
    
    var companyClass = '.company-tag-wrapper__1rBy a';
    var companyElems = $$(companyClass);
    var companies = companyElems.length? `**Companies**:  \n${companyElems.map(x => `[${$('.btn-content__lOBM', x).textContent}](${x.href})`).join(', ')}\n\n` : '';
    
    var topicClass = '.topic-tag__1jni';
    var topicElems = $$(topicClass);
    var topics = topicElems.length ?`**Related Topics**:  \n${topicElems.map(x => `[${x.textContent}](${x.href})`).join(', ')}\n\n` : '';
    
    var similarQuestionClass = '.question__25Pw';
    var similarQuestionTitleClass = '.title__1kvt';
    var similarQuestionDifficultyClass = '.difficulty__ES5S';
    var similarQuestonElems = $$(similarQuestionClass);
    var similarQuestions = similarQuestonElems.length ? `**Similar Questions**:\n${similarQuestonElems.map(x => { let link = $(similarQuestionTitleClass, x); return `* [${link.textContent} (${$(similarQuestionDifficultyClass,x).textContent})](${link.href})` }).join('\n')}\n\n` : '' ;
    
    copy(
        `${title}`
        + `${question}`
        + `${companies}`
        + `${topics}`
        + `${similarQuestions}`
        + `## Solution 1.\n\n\`\`\`cpp\n\n\`\`\``)
}(document)
