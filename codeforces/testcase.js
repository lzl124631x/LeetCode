let tests = $$('.sample-test .input pre');
copy(`${tests.length}\n${tests.map(x => x.textContent).join("")}`.trim());