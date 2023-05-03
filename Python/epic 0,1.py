import tweepy
import time
import random

consumer_key = "LUlC29Faili8aL8l9PRe6H8HD"
consumer_secret  = "NjkRROSdpZcyQYFvXXSLay3DsBREukihbSBWMh8gCsRoK37AMH"
access_token =  "1447357255381405696-SjuecQn73vSSHmwsKRohXpMbLBGMap"
access_token_secret = "2MH7L0rRvJ0nqw9j2CJzCPVpThC9mQU2kykIDGcSHotyr"

auth = tweepy.OAuth1UserHandler(
    consumer_key,
    consumer_secret,
    access_token,
    access_token_secret
)

api = tweepy.API(auth)

def get_tweet_message():
    messages = [
        'Hello Twitter!',
        'This is an automated tweet.',
        'I love Python!',
        'What a beautiful day.',
        'Check out my website!'
    ]
    return random.choice(messages)

while True:
    tweet_message = get_tweet_message()
    api.update_status(tweet_message)
    print('Tweeted:', tweet_message)
    time.sleep(3600) # Tweet every hour