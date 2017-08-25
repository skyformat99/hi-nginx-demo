<html>
    <head>
        </head>
    <p>
        FreeMarker Template example: ${message}  
        
        </p><hr />
    <p>
        =======================
===  County List   ====
=======================
        </p>
    <hr />
    <p>
        <ul>
            <#list countries as country>
	<li>${country_index + 1}. ${country}</li>
</#list>
            </ul>
        </p>
    <body></body>
    </html>



