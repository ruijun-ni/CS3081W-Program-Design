#include "gtest/gtest.h"
#include "queue.h"


class QueueTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
    q1 = Queue(); // the default capacity is 1000
    q2 = Queue(5);
    q3 = Queue(0);
  }
  void TearDown() {
    
  }
 protected:
  Queue q1;
  Queue q2;
  Queue q3;
};

/**
  * Test the constructor
  */
TEST_F(QueueTest, QueueConstructorTest) {
  EXPECT_EQ(q1.size(), 0) << "Wrong size";
  EXPECT_EQ(q1.getCapacity(), 1000) << "Wrong capacity";

  EXPECT_EQ(q2.size(), 0) << "Wrong size";
  EXPECT_EQ(q2.getCapacity(), 5) << "Wrong capacity";

  EXPECT_EQ(q3.size(), 0) << "Wrong size";
  EXPECT_EQ(q3.getCapacity(), 0) << "Wrong capacity";
}

/**
  * Test copy constructor
  * Queue(const Queue &q1)
  */
TEST_F(QueueTest, CopyConstructorTest) {
  Queue q(3);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  Queue q_copy = Queue(q);
  EXPECT_EQ(q_copy.size(), 3);
  EXPECT_EQ(q_copy.getCapacity(), 3);
  EXPECT_EQ(q_copy.peek(), 1);
  q_copy.dequeue();
  EXPECT_EQ(q_copy.peek(), 2);
  EXPECT_EQ(q_copy.size(), 2);

  Queue q4 = Queue();
  q4.enqueue(1);
  q4.enqueue(2);
  Queue q_copy2 = Queue(q4);
  EXPECT_EQ(q_copy2.size(), 2);
  EXPECT_EQ(q_copy2.getCapacity(), 1000);
  EXPECT_EQ(q_copy2.peek(), 1);
  q_copy2.dequeue();
  EXPECT_EQ(q_copy2.size(), 1);
  EXPECT_EQ(q_copy2.getCapacity(), 1000);
  EXPECT_EQ(q_copy2.peek(), 2);


  Queue q5(2);
  q5.enqueue(1);
  q5.enqueue(2);
  Queue q6 = Queue(q5);
  EXPECT_EQ(q6.size(), 2);
  EXPECT_EQ(q6.peek(), 1);
  q6.dequeue();
  EXPECT_EQ(q6.peek(), 2);

}

/**
  * Test isEmpty
  */
TEST_F(QueueTest, IsEmptyTest) {
  EXPECT_EQ(q1.isEmpty(), true);
  EXPECT_EQ(q2.isEmpty(), true);
  EXPECT_EQ(q3.isEmpty(), true);

  Queue q(1);
  EXPECT_EQ(q.isEmpty(), true);
  q.enqueue(1);
  EXPECT_EQ(q.isEmpty(), false);
}

/**
  * Test isFull
  */
TEST_F(QueueTest, IsFullTest) {
  EXPECT_EQ(q1.isFull(), false);
  EXPECT_EQ(q2.isFull(), false);

  Queue q(1);
  EXPECT_EQ(q.isFull(), false);
  q.enqueue(1);
  EXPECT_EQ(q.isFull(), true);
}

/**
  * Test size
  */
TEST_F(QueueTest, SizeTest) {
  EXPECT_EQ(q1.size(), 0);
  EXPECT_EQ(q2.size(), 0);
  EXPECT_EQ(q3.size(), 0);

  Queue q(1);
  EXPECT_EQ(q.size(), 0);
  q.enqueue(1);
  EXPECT_EQ(q.size(), 1);
  q.dequeue();
  EXPECT_EQ(q.size(), 0);
}

/**
  * Test indexOf
  */
TEST_F(QueueTest, IndexTest) {
  Queue q(4);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.dequeue();
  q.enqueue(5);
  EXPECT_EQ(q.indexOf(5), 3);
  EXPECT_EQ(q.indexOf(2), 0);
  EXPECT_EQ(q.indexOf(10), -1);
  q.dequeue();
  EXPECT_EQ(q.indexOf(2), -1);
  EXPECT_EQ(q.indexOf(4), 1);

  Queue q4 = Queue();
  q4.enqueue(1);
  q4.enqueue(2);
  EXPECT_EQ(q4.indexOf(1), 0);
  EXPECT_EQ(q4.indexOf(2), 1);
  EXPECT_EQ(q4.indexOf(3), -1);
  q4.dequeue();
  EXPECT_EQ(q4.indexOf(1), -1);
  EXPECT_EQ(q4.indexOf(2), 0);

  Queue q5(3);
  q5.enqueue(1);
  q5.enqueue(2);
  q5.enqueue(1);
  EXPECT_EQ(q5.indexOf(1), 0);
}

/**
  * Test clear
  */
TEST_F(QueueTest, ClearTest) {
  Queue q(2);
  q.enqueue(1);
  q.enqueue(2);
  q.clear();
  EXPECT_EQ(q.size(), 0) << "Wrong size";
  EXPECT_EQ(q.getCapacity(), 2) << "Wrong capacity";

  Queue q4 = Queue();
  for (int i = 1; i <= 1000; i++) {
    q4.enqueue(i);  
  }
  q4.clear();
  EXPECT_EQ(q4.size(), 0) << "Wrong size";
  EXPECT_EQ(q4.getCapacity(), 1000) << "Wrong capacity";

  Queue q5 = Queue(1);
  q5.enqueue(1);
  q5.clear();
  EXPECT_EQ(q5.size(), 0) << "Wrong size";
  EXPECT_EQ(q5.getCapacity(), 1) << "Wrong capacity";
  EXPECT_EQ(q.indexOf(1), -1) << "Wrong index";
}

/**
  * Test dequeue
  */
TEST_F(QueueTest, DequeueTest) {
  Queue q(3);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  EXPECT_EQ(q.size(), 3) << "Wrong size";
  EXPECT_EQ(q.indexOf(1), 0);
  int val = q.dequeue();
  EXPECT_EQ(val, 1) << "Dequeue not working right";
  EXPECT_EQ(q.indexOf(1), -1);
  val = q.dequeue();
  EXPECT_EQ(val, 2) << "Dequeue not working right";
  
  testing::internal::CaptureStdout();
  val = q.dequeue();
  std::string output = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(val, 3) << "Dequeue not working right";
  EXPECT_EQ(output, "Removing 3\n") << "Print Dequeue not working right";
}

/**
  * Test enqueue
  */
TEST_F(QueueTest, EnqueueTest) {
  Queue q(5);
  EXPECT_EQ(q.size(), 0) << "Wrong size";
  q.enqueue(1);
  EXPECT_EQ(q.size(), 1) << "Wrong size";
  q.enqueue(2);
  EXPECT_EQ(q.size(), 2) << "Wrong size";
  q.enqueue(3);
  EXPECT_EQ(q.size(), 3) << "Wrong size";

  Queue q4(2);
  EXPECT_EQ(q4.size(), 0) << "Wrong size";
  q4.enqueue(1);
  EXPECT_EQ(q4.size(), 1) << "Wrong size";
  q4.enqueue(2);
  EXPECT_EXIT(q4.enqueue(3), ::testing::ExitedWithCode(1), "");
}

/**
  * Test bubbleSort
  */
TEST_F(QueueTest, BubbleSortTest) {
    Queue q(4);
    q.enqueue(2147483647);
    q.enqueue(42);
    q.enqueue(38);
    q.enqueue(15);
    q.bubbleSort();
    EXPECT_EQ(q.indexOf(15), 0) << "Bubble Sort not working right";
    EXPECT_EQ(q.indexOf(38), 1) << "Bubble Sort not working right";
    EXPECT_EQ(q.indexOf(42), 2) << "Bubble Sort not working right";
    EXPECT_EQ(q.indexOf(2147483647), 3) << "Bubble Sort not working right";
}

/**
  * Test mergeSort
  */
TEST_F(QueueTest, MergeSortTest) {
    Queue q(4);
    q.enqueue(2147483647);
    q.enqueue(42);
    q.enqueue(38);
    q.enqueue(15);
    q.mergeSort();
    EXPECT_EQ(q.indexOf(15), 0) << "Merge Sort not working right";
    EXPECT_EQ(q.indexOf(38), 1) << "Merge Sort not working right";
    EXPECT_EQ(q.indexOf(42), 2) << "Merge Sort not working right";
    EXPECT_EQ(q.indexOf(2147483647), 3) << "Merge Sort not working right";
}

/**
  * Test size
  */
TEST_F(QueueTest, QueueSizeTest) {
    Queue q(4);
    EXPECT_EQ(sizeof(q), 24) << "Wrong size";
    q.enqueue(24);
    EXPECT_EQ(sizeof(q), 24) << "Wrong size";
    q.enqueue(42);
    q.enqueue(38);
    q.enqueue(15);
    EXPECT_EQ(sizeof(q), 24) << "Wrong size";
}