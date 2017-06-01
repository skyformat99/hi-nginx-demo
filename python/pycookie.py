key='SESSIONID'
if hi_req.has_cookie(key):
    hi_res.content('{k}={v}'.format(k=key,v=hi_req.get_cookie(key)))
else:
    hi_res.content('not found {}'.format(key))
hi_res.status(200)
