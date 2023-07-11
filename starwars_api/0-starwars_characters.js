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

request(url, function (error, response, body) {
    if (error) {
        console.log(error);
    } else {
        const characters = JSON.parse(body).characters;

        for (const character of characters) {
            request(character, function (error, response, body) {
                if (error) {
                    console.log(error);
                } else {
                    console.log(JSON.parse(body).name);
                }
            });
        }
    }
});
