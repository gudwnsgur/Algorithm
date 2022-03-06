import java.util.*
import java.io.*
import kotlin.collections.HashSet

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val tk = StringTokenizer(br.readLine())
    val n = Integer.parseInt(tk.nextToken())
    val m = Integer.parseInt(tk.nextToken())

    val noListener = HashSet<String>()
    val nothing = TreeSet<String>()

    for(i in 0 until n) {
        val name = br.readLine()
        noListener.add(name)
    }
    for(i in 0 until m) {
        val name = br.readLine()
        if(noListener.contains(name)) nothing.add(name)
    }
    println(nothing.size)
    for(i in nothing.iterator()) println(i)
}
