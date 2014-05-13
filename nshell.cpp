#include <cstdio>
using namespace std;

#include "curl/curl.h"

/*int main()
{
    CURL *curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://openapi.kuaipan.cn/1/account_info/?oauth_signature=x4UgXDKEngB7KJrVZZUYZ8k1EWY%3D&oauth_consumer_key=xcyOYbQfRhzJGQkV&oauth_nonce=1jfbWAdJ&oauth_signature_method=HMAC-SHA1&oauth_timestamp=1396967921&oauth_token=0042321d6590e0e63852635b&oauth_version=1.0");

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        CURLcode res = curl_easy_perform(curl);

        printf("res: %d\n", res);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_proform() failed: %s\n", 
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}
*/

