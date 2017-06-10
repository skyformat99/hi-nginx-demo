local test_key='test'
local test_value=0
if (hi_req:has_session(test_key))
then
    test_value = tonumber(hi_req:get_session(test_key))
    hi_res:content(string.format('%s=%s',test_key,test_value))
    hi_res:session(test_key,tostring(test_value+1))
else
    hi_res:session(test_key,tostring(test_value))
    hi_res:content(string.format('test=%s',test_value))
end
hi_res:status(200)
