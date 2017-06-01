data='{client},{method},{uri},{user_agent},{param}'.format(client=hi_req.client(),method=hi_req.method(),uri=hi_req.uri(),user_agent=hi_req.user_agent(),param=hi_req.param())
hi_res.content(data)
hi_res.status(200)
