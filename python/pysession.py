test_key='test'
test_value=0
if hi_req.has_session(test_key):
    test_value = int(hi_req.get_session(test_key))
    hi_res.content('{key}={value}'.format(key=test_key,value=test_value))
    hi_res.session(test_key,'{}'.format(test_value+1))
else:
    hi_res.session(test_key,'{}'.format(test_value))
    hi_res.content('test={}'.format(test_value))
hi_res.status(200)
