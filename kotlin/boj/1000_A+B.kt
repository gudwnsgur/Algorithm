import java.util.*
import java.io.*

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val tk = StringTokenizer(br.readLine())
    println(Integer.parseInt(tk.nextToken()) + Integer.parseInt(tk.nextToken()))
}
  