#include <gtest/gtest.h>
#include "RdbBase.h"
#include "Posdb.h"
#include "GigablastTestUtils.h"
#include "Conf.h"

class RdbBaseTest : public ::testing::Test {
public:
	void SetUp() {
		GbTest::initializeRdbs();
	}

	void TearDown() {
		GbTest::resetRdbs();
	}
};

class RdbBasePosdbIndexSingleDocTest : public RdbBaseTest, public ::testing::WithParamInterface<::testing::tuple<int64_t, int64_t, int64_t>> {
};

INSTANTIATE_TEST_CASE_P(RdbBasePosdbIndexSingleDoc,
                        RdbBasePosdbIndexSingleDocTest,
                        ::testing::Combine(::testing::Values(POSDB_DELETEDOC_TERMID, 1),
                                           ::testing::Values(POSDB_DELETEDOC_TERMID, 1),
                                           ::testing::Values(POSDB_DELETEDOC_TERMID, 1)));

TEST_P(RdbBasePosdbIndexSingleDocTest, PosdbGenerateIndexSingleDocId) {
	const collnum_t collNum = 0;
	const int64_t docId = 1;
	int32_t fileId = 0;

	RdbBase *base = g_posdb.getRdb()->getBase(collNum);

	ASSERT_EQ(0, base->addNewFile(&fileId));
	RdbIndex *index0 = base->getIndex(0);
	int64_t termId0 = ::testing::get<0>(GetParam());
	GbTest::addPosdbKey(index0, termId0, docId, 0, ::testing::get<0>(GetParam()) == POSDB_DELETEDOC_TERMID);
	index0->writeIndex(true);
	base->markNewFileReadable();

	ASSERT_EQ(1, base->addNewFile(&fileId));
	RdbIndex *index1 = base->getIndex(1);
	int64_t termId1 = ::testing::get<1>(GetParam());
	GbTest::addPosdbKey(index1, termId1, docId, 0, ::testing::get<1>(GetParam()) == POSDB_DELETEDOC_TERMID);
	index1->writeIndex(true);
	base->markNewFileReadable();

	ASSERT_EQ(2, base->addNewFile(&fileId));
	RdbIndex *index2 = base->getIndex(2);
	int64_t termId2 = ::testing::get<2>(GetParam());
	GbTest::addPosdbKey(index2, termId2, docId, 0, ::testing::get<2>(GetParam()) == POSDB_DELETEDOC_TERMID);
	index2->writeIndex(true);
	base->markNewFileReadable();

	base->generateGlobalIndex();
	auto globalIndex = base->getGlobalIndex();
	ASSERT_EQ(1, globalIndex->size());
	int64_t result = (((docId << RdbIndex::s_docIdOffset) | (!termId2 == POSDB_DELETEDOC_TERMID)) << RdbBase::s_docIdFileIndex_docIdOffset | 2);
	EXPECT_EQ(result, *globalIndex->begin());
}

TEST_F(RdbBaseTest, PosdbUpdateIndex) {
	const collnum_t collNum = 0;
	int32_t fileId = 0;

	RdbBase *base = g_posdb.getRdb()->getBase(collNum);

	ASSERT_EQ(0, base->addNewFile(&fileId));
	RdbIndex *index0 = base->getIndex(0);
	GbTest::addPosdbKey(index0, 'A', 1, 0);
	index0->writeIndex(true);
	base->markNewFileReadable();

	ASSERT_EQ(1, base->addNewFile(&fileId));
	RdbIndex *index1 = base->getIndex(1);
	GbTest::addPosdbKey(index1, 'B', 2, 0);
	index1->writeIndex(true);
	base->markNewFileReadable();

	ASSERT_EQ(2, base->addNewFile(&fileId));
	RdbIndex *index2 = base->getIndex(2);
	GbTest::addPosdbKey(index2, 'C', 3, 0);
	index2->writeIndex(true);
	base->markNewFileReadable();

	ASSERT_EQ(3, base->addNewFile(&fileId));
	RdbIndex *index3 = base->getIndex(3);
	GbTest::addPosdbKey(index3, 'D', 4, 0);
	index3->writeIndex(true);
	base->markNewFileReadable();

	ASSERT_EQ(4, base->addNewFile(&fileId));
	RdbIndex *index4 = base->getIndex(4);
	GbTest::addPosdbKey(index4, 'E', 5, 0);
	index4->writeIndex(true);
	base->markNewFileReadable();

	ASSERT_EQ(5, base->addNewFile(&fileId));
	RdbIndex *index5 = base->getIndex(5);
	GbTest::addPosdbKey(index5, 'F', 6, 0);
	index5->writeIndex(true);
	base->markNewFileReadable();

	base->generateGlobalIndex();
	{
		auto globalIndex = base->getGlobalIndex();
		ASSERT_EQ(6, globalIndex->size());

		EXPECT_EQ((((1 << RdbIndex::s_docIdOffset) | 1) << RdbBase::s_docIdFileIndex_docIdOffset) | 0, globalIndex->at(0));
		EXPECT_EQ((((2 << RdbIndex::s_docIdOffset) | 1) << RdbBase::s_docIdFileIndex_docIdOffset) | 1, globalIndex->at(1));
		EXPECT_EQ((((3 << RdbIndex::s_docIdOffset) | 1) << RdbBase::s_docIdFileIndex_docIdOffset) | 2, globalIndex->at(2));
		EXPECT_EQ((((4 << RdbIndex::s_docIdOffset) | 1) << RdbBase::s_docIdFileIndex_docIdOffset) | 3, globalIndex->at(3));
		EXPECT_EQ((((5 << RdbIndex::s_docIdOffset) | 1) << RdbBase::s_docIdFileIndex_docIdOffset) | 4, globalIndex->at(4));
		EXPECT_EQ((((6 << RdbIndex::s_docIdOffset) | 1) << RdbBase::s_docIdFileIndex_docIdOffset) | 5, globalIndex->at(5));
	}
}
