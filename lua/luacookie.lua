local key='SESSIONID'
if (hi_req:has_cookie(key))
then 
    hi_res:content(string.format('%s=%s',key,hi_req:get_cookie(key)))
else
    hi_res:content(string.format('not found %s',key))
end
hi_res:status(200)
