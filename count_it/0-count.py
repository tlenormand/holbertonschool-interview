#!/usr/bin/python3
""" Count it """

import requests


def count_words(subreddit, word_list, after=None, word_count={}):
    """ function that queries the Reddit API,
        parses the title of all hot articles,
        and prints a sorted count of given keywords
        Args:
            subreddit: subreddit supplied
            word_list: list of keywords
            after
    """
    if after is None:
        url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    else:
        url = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(subreddit,
                                                                     after)
    response = requests.get(url,
                            headers={'User-agent': 'Holberton'},
                            allow_redirects=False)

    if response.status_code != 200:
        return None

    lower_word_list = []
    for word in word_list:
        lower_word_list.append(word.lower())

    for word in lower_word_list:
        if word not in word_count.keys():
            word_count[word] = 0

    hot_articles = response.json()['data']['children']
    hot_title = []
    for article in hot_articles:
        hot_title = (article['data']['title'].lower().split())
        for word in lower_word_list:
            word_count[word] += hot_title.count(word)

    after = response.json()['data']['after']
    if after is not None:
        return count_words(subreddit, word_list, after, word_count)
    else:
        sorted_word_count = sorted(
            word_count.items(),
            key=lambda x: -x[1]
        )

        for word in sorted_word_count:
            if word[1] != 0:
                print('{}: {}'.format(word[0], word[1]))
