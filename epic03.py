import tweepy

# Credenciais
consumer_key = "LUlC29Faili8aL8l9PRe6H8HD"
consumer_secret = "NjkRROSdpZcyQYFvXXSLay3DsBREukihbSBWMh8gCsRoK37AMH"
bearer_token = "AAAAAAAAAAAAAAAAAAAAADVonAEAAAAAJiub13B3BDjAfKIWINrRdz4L7fI"
access_token = "1447357255381405696-SjuecQn73vSSHmwsKRohXpMbLBGMap"
access_token_secret = "2MH7L0rRvJ0nqw9j2CJzCPVpThC9mQU2kykIDGcSHotyr"

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)

api = tweepy.API(auth, bearer_token=bearer_token)

# Enviando tweet
tweet_message = "Hello, world!"
tweet = api.update_status(status=tweet_message)