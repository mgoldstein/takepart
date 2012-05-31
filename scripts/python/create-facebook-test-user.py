import json
import urllib2
import sys
import time

class FacebookAPI(object):

  APP_ID = '247137505296280'
  APP_SECRET = '9278ba54095f2994812790292750a696'

  def __init__(self):

    options = {
      'client_id': self.APP_ID,
      'client_secret': self.APP_SECRET,
      'grant_type': 'client_credentials'
    }
    
    params = '&'.join(['='.join(pair) for pair in options.iteritems()])
    url = 'https://graph.facebook.com/oauth/access_token?%s' % (params,)
    response = self.urlread(url)

    (_,self.access_token) = response.strip().split('=')

  def urlread(self, url):
    data = ''
    p = urllib2.urlopen(url)
    chunk = p.read(100)
    while len(chunk) > 0:
      data += chunk
      chunk = p.read(100)
    return data

  def create_user(self, name):

    options = {
      'installed': 'true',
      'name': name.replace(' ', '%20'),
      'locale': 'en_US',
      'permissions': 'read_stream',
      'method': 'post',
      'access_token': self.access_token
    }
    params = '&'.join(['='.join(pair) for pair in options.iteritems()])
    url = 'https://graph.facebook.com/%s/accounts/test-users?%s' % (self.APP_ID, params)
    print 'Requesting account for %s' % (name,)
    try:
      user = json.load(urllib2.urlopen(url))
    except urllib2.HTTPError, e:
      print '** Error requesting user. **'
      print '   Name: ' + name
      print '   URL:  ' + url
      user = None
    return user

def generate_name(seed = None):

  # use the time as a seed if one was not provided
  if seed is None: 
    seed = int(time.time() * 100)
  
  # convert the seed to a base 26 number (offset to start at 'a')
  digits = []
  while 1:
    digits.append((seed % 26) + 97)
    seed = seed / 26
    if seed == 0:
      break
  
  # mix the digits up so we get more distinct names when
  # generating one right after another
  odds = [digits[i] for i in range(1, len(digits), 2)]
  odds.reverse()
  evens = [digits[i] for i in range(0, len(digits), 2)]
  name = evens + odds
  
  # capitalize the first letter
  if len(name) > 0:
    name[0] -= 32
  
  # return the name as a string
  return ''.join(map(chr, name))
   
if __name__ == '__main__':

  if len(sys.argv) == 1:
    name = 'TakePart ' + generate_name()
  elif len(sys.argv) == 2:
    name = sys.argv[1]
  else:
    print 'usage: python %s ["User Name"]' % (sys.argv[0],)
    sys.exit(1)
    
  fb = FacebookAPI()
  user = fb.create_user(name)
  if user is not None:
    print 'Email: %s' % (user['email'],)
    print 'Password: %s' % (user['password'],)


