#!/usr/bin/python3
""" Count it """

import requests


def count_words(subreddit, word_list):
    """ Function that queries the Reddit API, parses the title of all hot
        articles, and prints a sorted count of given keywords
    """
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-Agent': 'CustomClient/1.0'}
    params = {'limit': 100}
    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )
    if response.status_code != 200:
        return None

    data = response.json()
    hot_posts = data.get('data').get('children')
    hot_titles = [post.get('data').get('title') for post in hot_posts]

    count_dict = {}
    for word in word_list:
        count_dict[word] = 0

    for title in hot_titles:
        words = title.split()
        for word in words:
            for key in count_dict.keys():
                if word.lower() == key.lower():
                    count_dict[key] += 1

    sorted_dict = sorted(count_dict.items(), key=lambda x: x[1], reverse=True)

    for key, value in sorted_dict:
        if value != 0:
            print('{}: {}'.format(key.lower(), value))
