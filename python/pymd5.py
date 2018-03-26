import hashlib
test = b'hello,md5!'
m = hashlib.md5()
m.update(test)
hi_res.status(200)
hi_res.content("{k} md5 = {v}".format(k=test,v=m.hexdigest()))
    
