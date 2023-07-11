#!/usr/bin/node

/*
JavaScript script that prints all characters of a Star Wars movie
API service: https://intranet.hbtn.io/rltoken/aiMsg1QkH-FuPn7gyo9O6A
use the request module
*/

const request = require('request');
const movieId = process.argv[2];

// Request URL
const url = 'https://swapi-api.hbtn.io/api/films/' + movieId;

request(url, async (error, response, body) => {
  if (error) { console.log(error); }

  const characters = JSON.parse(body).characters;

  console.log(characters);

  for await (const character of characters) {
    const name = await new Promise((resolve, reject) => {
      request(character, (error, response, body) => {
        if (error) { reject(error); }

        resolve(JSON.parse(body).name);
      });
    });

    console.log(name);
  }
});
