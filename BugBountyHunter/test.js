const https = require('https');

callback = (response) => {
    let data = '';
    response.on('data', (chunk) => {
        data += chunk;
    });

    response.on('end', () => {
        console.log(data);
    });
}

https.request('https://www.bugbountytraining.com/challenges/challenge-15.php?jsonp=userinfo', callback).end();