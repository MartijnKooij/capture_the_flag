const fs = require('fs');
const letters = 'abcdefghijklmnopqrstuvwxyz';

const userNames = [];
for (let a = 0; a < letters.length; a++) {
    for (let b = 0; b < letters.length; b++) {
        for (let c = 0; c < letters.length; c++) {
            userNames.push(letters[a] + letters[b] + letters[c]);
        }
    }
}

fs.writeFileSync('./usernames.txt', userNames.join('\r\n'));