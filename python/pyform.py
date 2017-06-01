key='a'
if hi_req.has_form(key):
    hi_res.content('{a}={value}'.format(a=key,value=hi_req.get_form(key)))
else:
    hi_res.content('Not found {}'.format(key))
hi_res.status(200)
