# A simple coroutine that simulates IO-bound work with asyncio.sleep
async def simulate_io_work(work_id, work_time):
    print(f"Work {work_id} started, will take {work_time} seconds.")
    await asyncio.sleep(work_time)
    print(f"Work {work_id} completed.")
    return work_time

# A simple coroutine that raises an exception
async def raise_exception():
    print("Raising exception.")
    await asyncio.sleep(1)
    raise ValueError("An error occurred")

# Test cases
async def test_simulate_io_work():
    # Test awaiting on a completed task
    print("Testing simulate_io_work with completed task.")
    task = asyncio.create_task(simulate_io_work(1, 1))
    await asyncio.sleep(2)  # Ensure the task has time to complete
    assert task.done()

    # Test awaiting on a running task
    print("Testing simulate_io_work with running task.")
    task = asyncio.create_task(simulate_io_work(2, 2))
    await asyncio.sleep(1)  # Ensure the task has time to start but not finish
    assert not task.done()

    # Test awaiting on a cancelled task
    print("Testing simulate_io_work with cancelled task.")
    task = asyncio.create_task(simulate_io_work(3, 3))
    await asyncio.sleep(1)  # Ensure the task has time to start
    task.cancel()
    try:
        await task
    except asyncio.CancelledError:
        print("Task was cancelled as expected.")
    else:
        print("Task was not cancelled as expected.")

async def test_raise_exception():
    # Test awaiting on a task that raises an exception
    print("Testing raise_exception.")
    task = asyncio.create_task(raise_exception())
    try:
        await task
    except ValueError:
        print("Exception was raised as expected.")
    else:
        print("Exception was not raised as expected.")

# Run the tests
loop = asyncio.get_event_loop()
loop.run_until_complete(test_simulate_io_work())
loop.run_until_complete(test_raise_exception())