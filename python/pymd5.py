import md5
test = 'hello,md5!'
m = md5.new()
m.update(test)
hi_res.status(200)
hi_res.content("{k} md5 = {v}".format(k=test,v=m.hexdigest()))
    
