local MD5 = require "md5"
local test="hello,md5!"
hi_res:status(200)
hi_res:content(string.format("%s md5 = %s",test,MD5.sumhexa(test)))