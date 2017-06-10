if (hi_req:has_header('Connection'))
then
    hi_res:content(hi_req:get_header('Connection'))
else
    hi_res:content(string.format('Not found %s header','Connection'))
end
hi_res:header('test-header','lua')
hi_res:status(200)
