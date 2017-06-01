if hi_req.has_header('Connection'):
    hi_res.content(hi_req.get_header('Connection'))
else:
    hi_res.content('Not found {} header'.format('Connection'))
hi_res.header('test-header','python')
hi_res.status(200)
