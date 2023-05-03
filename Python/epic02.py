import tweepy
import time
import random

# Credenciais
consumer_key = "QKxUBnBOTSxhMwYLWs3W2LqY2"
consumer_secret = "LcEx0j6DisBJcS0FmaqFVpEdxzTB0NSkjm2gSC3PL9BEQGVjBd"
access_token = "1447357255381405696-GipG5c56CC8N7gmfinjbA3pAomq62J"
access_token_secret = "cJ1dp8OhoW8psiBhZXtJk1wuPNv8JArsEpxsiBvly6ZXI"

# Autentificando o Twitter API
auth = tweepy.OAuthHandler(
    consumer_key,
    consumer_secret
)

auth.set_access_token(
    access_token,
    access_token_secret
)

api = tweepy.API(auth)

