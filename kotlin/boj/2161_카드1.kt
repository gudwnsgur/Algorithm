import java.util.*

val deque =  ArrayDeque<Int>()

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    for(i in 1..n) deque.add(i)

    while(deque.size > 1) {
        print("${deque.pollFirst()} ")
        deque.add(deque.pollFirst())
    }
    print("${deque.pollFirst()}")
}
