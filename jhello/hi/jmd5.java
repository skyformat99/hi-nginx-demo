package hi;

public class jmd5 implements hi.servlet {

    public jmd5() {
    }

    public void handler(hi.request req, hi.response res) {
        String plaintext = "hello,md5!";
        res.status = 200;
        res.content = String.format("%s md5= %s", plaintext, this.MD5(plaintext));
    }

    private String MD5(String md5) {
        try {
            java.security.MessageDigest md = java.security.MessageDigest.getInstance("MD5");
            byte[] array = md.digest(md5.getBytes());
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < array.length; ++i) {
                sb.append(Integer.toHexString((array[i] & 0xFF) | 0x100).substring(1, 3));
            }
            return sb.toString();
        } catch (java.security.NoSuchAlgorithmException e) {
        }
        return null;
    }
}
