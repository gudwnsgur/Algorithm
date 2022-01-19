import java.util.*
import java.io.*

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val n = Integer.parseInt(br.readLine())
    val str = arrayOfNulls<String>(n)
    str[0] = br.readLine()

    val result = CharArray(str[0]!!.length)
    for (i in result.indices) result[i] = str[0]!![i]
    for (i in 1 until n) {
        str[i] = br.readLine()
        for (j in 0 until str[i]!!.length) {
            if (result[j] != str[i]!![j]) result[j] = '?'
        }
    }
    for (char in result) print(char)
}
