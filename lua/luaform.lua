local key='a'
if (hi_req:has_form(key))
then
    hi_res:content(string.format('%s=%s',key,hi_req:get_form(key)))
else
    hi_res:content(string.format('Not found %s',key))
end
hi_res:status(200)
