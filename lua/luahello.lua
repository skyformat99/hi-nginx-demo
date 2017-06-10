local data=string.format('%s,%s,%s,%s,%s',hi_req:client(),hi_req:method(),hi_req:uri(),hi_req:user_agent(),hi_req:param())
hi_res:content(data)
hi_res:status(200)


